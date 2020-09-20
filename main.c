/* unencrypted_crashdump
 *
 * Copyright (C) 2020 chen-charles
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <taihen.h>
#include <vitasdkkern.h>

static SceUID hookid = -1;
static tai_hook_ref_t g_crashdump_hook;

static int sceSblACMgrIsAllowCoredumpForDriver_hook(int ctx, SceUID pid)
{
    int ret;
    ret = TAI_CONTINUE(int, g_crashdump_hook, ctx, pid);
    if (ret == 0)
        ret = 1;
    return ret;
}

void _start() __attribute__((weak, alias("module_start")));
int module_start(SceSize args, void *argp)
{
    hookid = taiHookFunctionExportForKernel(KERNEL_PID,
                                            &g_crashdump_hook,
                                            "SceSblACMgr",
                                            0x9AD8E213, // SceSblACMgrForDriver
                                            0x4CBD6156, // int sceSblACMgrIsAllowCoredumpForDriver(SceUID pid);
                                            sceSblACMgrIsAllowCoredumpForDriver_hook);
    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize args, void *argp)
{
    if (hookid >= 0)
        taiHookReleaseForKernel(hookid, g_crashdump_hook);

    return SCE_KERNEL_STOP_SUCCESS;
}
