/* Libvisual-AVS - Advanced visual studio for libvisual
 * 
 * Copyright (C) 2005 Dennis Smit <ds@nerds-incorporated.org>
 *
 * Authors: Dennis Smit <ds@nerds-incorporated.org>
 *
 * $Id:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _LV_LVAVS_PIPELINE_H
#define _LV_LVAVS_PIPELINE_H

#include <libvisual/libvisual.h>

#include "lvavs_preset.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define LVAVS_PIPELINE(obj)				(VISUAL_CHECK_CAST ((obj), 0, LVAVSPipeline))
#define LVAVS_PIPELINE_RENDERSTATE(obj)			(VISUAL_CHECK_CAST ((obj), 0, LVAVSPipelineRenderState))
#define LVAVS_PIPELINE_ELEMENT(obj)			(VISUAL_CHECK_CAST ((obj), 0, LVAVSPipelineElement))
#define LVAVS_PIPELINE_CONTAINER(obj)			(VISUAL_CHECK_CAST ((obj), 0, LVAVSPipelineContainer))


typedef struct _LVAVSPipeline LVAVSPipeline;
typedef struct _LVAVSPipelineRenderState LVAVSPipelineRenderState;
typedef struct _LVAVSPipelineElement LVAVSPipelineElement;
typedef struct _LVAVSPipelineContainer LVAVSPipelineContainer;


typedef enum {
	LVAVS_PIPELINE_ELEMENT_TYPE_NULL,
	LVAVS_PIPELINE_ELEMENT_TYPE_ACTOR,
	LVAVS_PIPELINE_ELEMENT_TYPE_TRANSFORM,
	LVAVS_PIPELINE_ELEMENT_TYPE_MORPH,
	LVAVS_PIPELINE_ELEMENT_TYPE_RENDERSTATE,
	LVAVS_PIPELINE_ELEMENT_TYPE_CONTAINER
} LVAVSPipelineElementType;

typedef enum {
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_REPLACE,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_ADDITIVE,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_MAXIMUM,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_5050,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_SUBSTRACT1,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_SUBSTRACT2,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_MULTIPLY,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_ADJUSTABLE,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_XOR,
	LVAVS_PIPELINE_RENDER_STATE_BLEND_TYPE_MINIMUM
} LVAVSPipelineRenderStateBlendMode;

/* The AVS data structure */
struct _LVAVSPipeline {
	VisObject			 object;

	int				 clearframe;

	LVAVSPipelineRenderState	*renderstate;

	VisVideo			*target;

//	VisVideo			*buffers[16];

	LVAVSPipelineContainer		*container;
};

struct _LVAVSPipelineRenderState {
	VisObject			 	object;

	int				 	enabled;

	unsigned char			 	blendadjust;

	LVAVSPipelineRenderStateBlendMode	blendmode;

	int				 	linewidth;
};

struct _LVAVSPipelineElement {
	VisObject			 object;

	LVAVSPipelineElementType	 type;

	LVAVSPipeline			*pipeline;

	union {
		VisActor			*actor;
		VisMorph			*morph;
//		VisTransform			*trans;
		LVAVSPipelineRenderState	*renderstate;
		LVAVSPipelineContainer		*container;
	} data;
};

struct _LVAVSPipelineContainer {
	LVAVSPipelineElement		 element;

	VisList				*members;
};


/* Prototypes */
LVAVSPipeline *lvavs_pipeline_new ();
LVAVSPipelineElement *lvavs_pipeline_element_new (LVAVSPipelineElementType type);
LVAVSPipelineContainer *lvavs_pipeline_container_new ();

LVAVSPipeline *lvavs_pipeline_new_from_preset (LVAVSPreset *preset);
int lvavs_pipeline_realize (LVAVSPipeline *pipeline);
int lvavs_pipeline_negotiate (LVAVSPipeline *pipeline, VisVideo *video);
int lvavs_pipeline_run (LVAVSPipeline *pipeline, VisVideo *video, VisAudio *audio);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LV_LVAVS_PIPELINE_H */
