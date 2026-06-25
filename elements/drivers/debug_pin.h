// Copyright 2012 Emilie Gillet. MIT License (see LICENSE).
//
// Debug (timing) pin driver. MAGDA fork: hardware GPIO stripped, no-op so the
// DSP compiles off-target. TIC/TOC become nothing.

#ifndef ELEMENTS_DRIVERS_DEBUG_PIN_H_
#define ELEMENTS_DRIVERS_DEBUG_PIN_H_

#include "stmlib/stmlib.h"

namespace elements {

class DebugPin {
 public:
  DebugPin() { }
  ~DebugPin() { }
  static void Init() { }
  static void High() { }
  static void Low() { }
 private:
  DISALLOW_COPY_AND_ASSIGN(DebugPin);
};

#define TIC
#define TOC

}  // namespace elements

#endif  // ELEMENTS_DRIVERS_DEBUG_PIN_H_
