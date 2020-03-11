# download the syphyr kernel source

```git clone -b lineage-16.0 https://github.com/syphyr/android_kernel_samsung_msm8976.git```

# download the google cross compiler, depth=1 is sufficient, don't need the commit history for it

```git clone --depth=1 https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/```

**You will need to use specific version, or else will fail building, aka use this version:**

https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/+/22f053ccdfd0d73aafcceff3419a5fe3c01e878b

# download wireguard

```git clone --depth=1 https://git.zx2c4.com/wireguard-linux-compat```

You can use the snapshot version too.

**You will need to manually adjust:**

https://github.com/htes9/kernel-syphyr-compiled/blob/master/wireguard_fix_dst_cache.c

**and**

https://github.com/htes9/kernel-syphyr-compiled/blob/master/wireguard_fix_udp_tunnel.c

**as reported by the diffs above**

# setup the cross compiler
```cd aarch64-linux-android-4.9```

```export CROSS_COMPILE=$(pwd)/bin/aarch64-linux-android-```

# set the architecture

```export ARCH=arm64 && export SUBARCH=arm64```

# build the kernel

```cd ../android_kernel_samsung_msm8976```

```make clean```

```make mrproper```

```make gts210vewifi_defconfig```

```make -j$(nproc --all)```

# you will probably get the error message "msm_dba_internal.h not found"
# fix it by changing the include

```sed -i 's/#include <msm_dba_internal.h>/#include "msm_dba_internal.h"/' drivers/video/msm/msm_dba/msm_dba.c```

# re-launch the build process

```make -j$(nproc --all)```
