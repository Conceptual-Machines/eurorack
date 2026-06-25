# eurorack (MAGDA fork)

Trimmed fork of [pichenettes/eurorack](https://github.com/pichenettes/eurorack)
by Emilie Gillet (Mutable Instruments), kept for MAGDA's native instrument and
FX ports of Elements, Rings and Clouds.

All code here is Emilie Gillet's, MIT licensed (these are the STM32F modules).
See `LICENSE`.

## What this fork keeps

- `stmlib/` (dsp, fft, utils) - shared DSP/math helpers, flattened in from the
  former `stmlib` submodule.
- `elements/dsp/`, `rings/dsp/`, `clouds/dsp/` plus each module's
  `resources.{cc,h}` - the DSP only.

Everything else (other modules, AVR libraries, bootloaders, firmware glue,
UI/CV/settings code, nested submodules) has been removed.

## Building off-target

Compile the DSP with `-DTEST`. stmlib's `TEST` path substitutes portable C for
the Cortex-M4 inline asm (saturating arithmetic, sqrt) and drops firmware-only
section attributes; the results are numerically equivalent. `drivers/debug_pin.h`
is reduced to a no-op in this fork.

Include root is the repository root (sources use `#include "elements/dsp/..."`
and `#include "stmlib/..."`).
