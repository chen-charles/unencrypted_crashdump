# unencrypted_crashdump
PS Vita: always generate psp2dmp instead of spsp2dmp

## Build
You need the latest version of [vitasdk](https://vitasdk.org/).  
```bash
$ mkdir -p build && cd build
$ cmake ../
$ make
```

## Install
* Copy `unencrypted_crashdump.skprx` to `ur0:tai/`
* In `ur0:tai/config.txt`'s `*KERNEL` section, create a new line and write: `ur0:tai/unencrypted_crashdump.skprx`
* Reboot

## Credits
[taiHen](https://tai.henkaku.xyz/)  
[Vita Development Wiki](https://wiki.henkaku.xyz/)

## Further
[CrashDumpEnabler](https://github.com/CelesteBlue-dev/CrashDumpEnabler) if you cannot find dumps under `ux0:data`.  
[vita-parse-core](https://github.com/xyzz/vita-parse-core)
