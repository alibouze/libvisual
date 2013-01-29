/* Libvisual - The audio visualisation framework.
 *
 * Copyright (C) 2012      Libvisual team
 *               2004-2006 Dennis Smit
 *
 * Authors: Chong Kai Xiong <kaixiong@codeleft.sg>
 *          Dennis Smit <ds@nerds-incorporated.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef _LV_AUDIO_STREAM_HPP
#define _LV_AUDIO_STREAM_HPP

#include "lvconfig.h"
#include "lv_defines.h"
#include "lv_buffer.h"
#include "lv_time.h"

#include <memory>

namespace LV {

  class AudioStream
  {
  public:

      AudioStream ();

      AudioStream (AudioStream const&) = delete;

      ~AudioStream ();

      AudioStream& operator= (AudioStream const&) = delete;

      std::size_t get_size () const;

      void write (BufferConstPtr const& buffer, Time const& timestamp);

      std::size_t read (BufferPtr const& data, std::size_t nbytes);

  private:

      class Impl;

      const std::unique_ptr<Impl> m_impl;
  };

} // LV namespace

#endif // _LV_AUDIO_STREAM_HPP
