
## Discord 
[Join the discord server for help](https://discord.gg/pG369jZbwd)
# Advanced-Lua-Script-Execution

This product is only for educational purposes, we do not encourage using this in online sessions





## Authors

- [@Llfpss - Shadow](https://github.com/llfpss)
- [@Speedy](https://github.com/SpeedyThePaster)
- [@Polar](https://github.com/Polaroot)
- [@Fuse](https://github.com/FuseWasTaken)

## Ini Configuring

First of all remember that this ini system takes restart of process to apply results since it's loaded in startup of the dll. To get access to this ini system first load the dll in main menu so that we can create the base config.ini to your C:/Plugins folder

| blacklist             | funtionality                                                                |
| ----------------- | ------------------------------------------------------------------ |
| input resource name | Can be set as 1 or 0: If set to 1 means the resource will be blacklisted: Example below| 
| spawnmanager | 1 |

| config             | funtionality                                                                |
| ----------------- | ------------------------------------------------------------------ |
| cache | Can be set as 1 or 0: If set to 0 Cache Saving is disabled | 
| execution | Can be set as 1 or 0: If set to 0 Script Execution is disabled |
| script | Where the script is located: Example: C:\\Plugins\\Custom.lua   |

| target             | funtionality                                                                |
| ----------------- | ------------------------------------------------------------------ |
| resource | You can specify exact resource to inject into: Example: spawnmanager | 
| index | You can specify exact script from the resource to inject into: These indexes can be found from the cache saver, for example script_0 from resource means that index of script is 0 |
| replace | Can be set to 0 or 1, If set to 1 the script execution will replace the original script with the script we have given it, If set to 0 it will insert our given script after the script.    |

## FAQ

#### Can i resell this product

No you cannot, the updates to our github will stop soon as people start reselling

#### Is there chances of getting banned?

There is always chances of getting banned, and we are not responsible if you do.

#### What can i do if it doesn't work for me?

You can join our discord and ask for help, we do not answer if the issue is publicly noted already in our channels

Most commons bugs:
The cache saving might not work in all of the server as functional which might cause script execution not to work, 
Try setting cache to 0 from the config.ini to resolve this possible bug

## Acknowledgements

 - [Used pINI api from Polar](https://github.com/Polaroot)

