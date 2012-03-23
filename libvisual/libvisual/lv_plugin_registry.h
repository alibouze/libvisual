#ifndef _LV_PLUGIN_REGISTRY_H
#define _LV_PLUGIN_REGISTRY_H

#include <libvisual/lv_defines.h>

VISUAL_BEGIN_DECLS

int visual_init_path_add (char *path);
int visual_plugin_registry_initialize (void);
int visual_plugin_registry_deinitialize (void);

VISUAL_END_DECLS

#endif /*_LV_PLUGIN_REGISTRY_H */