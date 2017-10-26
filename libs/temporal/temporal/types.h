/*
    Copyright (C) 2017 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __libtemporal_types_h__
#define __libtemporal_types_h__

#include <stdint.h>

namespace Temporal {

/* Any position measured in audio samples.
   Assumed to be non-negative but not enforced.
*/
typedef int64_t samplepos_t;

/* Any distance from a given samplepos_t.
   Maybe positive or negative.
*/
typedef int64_t sampleoffset_t;

/* Any count of audio samples.
   Required to be positive, but not enforced.
*/
typedef int64_t samplecnt_t;

static const samplepos_t max_samplepos = INT64_MAX;
static const samplecnt_t max_samplecnt = INT64_MAX;

/* This defines the smallest division of a "beat".

   The number is intended to have as many integer factors as possible so that
   1/Nth divisions are integer numbers of ticks.

   1920 has many factors, though going up to 3840 gets a couple more.
*/

static const int32_t ticks_per_beat = 1920;

enum LockStyle {
	/* simple ordinals, since these are mutually exclusive */
	AudioTime = 0,
	BeatTime = 1,
	BarTime = 2,
};

enum Dirty {
	/* combinable */
	SampleDirty = 0x1,
	BeatsDirty = 0x2,
	BBTDirty = 0x4
};

}

#endif /* __libtemporal_types_h__ */