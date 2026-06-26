// Copyright 2014 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Simple AD envelope - adapted from Peaks' multistage envelope.

#include "elements/dsp/multistage_envelope.h"

#include <algorithm>

namespace elements {

using namespace std;
using namespace stmlib;

void MultistageEnvelope::Init() {
  // On the original hardware this object lives in zero-initialized BSS, so the
  // segment-array entries past the active ADSR segments read as 0. Off-target
  // (e.g. in MAGDA's heap-allocated Part) that memory is indeterminate, and the
  // "done" state (segment_ == num_segments_) reads shape_[segment_] /
  // level_[segment_ + 1] past what set_adsr() fills -- a garbage shape_ indexes
  // lookup_table_table out of bounds and crashes Interpolate8. Zero the full
  // arrays up front to restore the firmware's assumption.
  std::fill(level_, level_ + kMaxNumSegments, 0.0f);
  std::fill(time_, time_ + kMaxNumSegments, 0.0f);
  std::fill(shape_, shape_ + kMaxNumSegments, ENV_SHAPE_LINEAR);
  set_adsr(0, 0.25f, 0.25f, 0.5f);
  segment_ = num_segments_;
  phase_ = 0.0f;
  start_value_ = 0.0f;
  value_ = 0.0f;
  hard_reset_ = false;
}

}  // namespace elements