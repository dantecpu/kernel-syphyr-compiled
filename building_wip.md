# Download the syphyr kernel source:

`git clone -b lineage-16.0 https://github.com/syphyr/android_kernel_samsung_msm8976.git`

## Download the gcc, depth=1 is sufficient, you don't need the commit history for it:

`git clone --depth=1 https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/`

**You will need to use a specific version of gcc, else will fail building:**

https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/+/22f053ccdfd0d73aafcceff3419a5fe3c01e878b

# Download wireguard:

```git clone --depth=1 https://git.zx2c4.com/wireguard-linux-compat```

**Modify the wireguard sources to allow compilation:**

https://github.com/htes9/kernel-syphyr-compiled/blob/master/wireguard_fix_dst_cache.c

https://github.com/htes9/kernel-syphyr-compiled/blob/master/wireguard_fix_udp_tunnel.c

# Configure the cross compiler:
`cd aarch64-linux-android-4.9`

`export CROSS_COMPILE=$(pwd)/bin/aarch64-linux-android-`

## Set the architecture:

`export ARCH=arm64 && export SUBARCH=arm64`

# Build the kernel:

`cd ../android_kernel_samsung_msm8976`

`make clean`

`make mrproper`

`make gts210vewifi_defconfig`

`make -j$(nproc --all)`

You will probably get the error message "msm_dba_internal.h not found", fix it by changing the include:

**sed -i 's/#include <msm_dba_internal.h>/#include "msm_dba_internal.h"/' drivers/video/msm/msm_dba/msm_dba.c**

## Re-launch the build process

`make -j$(nproc --all)`
