# v0.1.1

## Simple privilege escalation prevention

Patch:
/etc/passwd with permissions for others to write is one way for script with malicious intent gain root access.

```bash 
stat /etc/passwd
```

``` 
File: /etc/passwd
Size: 1882            Blocks: 8          IO Block: 4096   regular file
Device: 8,2     Inode: 6601539     Links: 1
Access: (0644/-rw-r--rw-)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2026-09-13 18:39:07.228999985 +0800
Modify: 2026-09-06 19:31:00.576191581 +0800
Change: 2026-09-06 19:31:00.622390662 +0800
Birth: 2026-09-06 19:31:00.575390840 +0800
```

with a normal user being able to write on to the /etc/passwd file that would mean an exploitative payload can be made 

e.g:
```python 
from os import environ
from pathlib import Path

shell = environ['SHELL']
user = "newroot"
pd = "$1$htf4psnX$PBKknYNMo2cq0bvOYtpt./"
payload = f"{user}:{pd}:0:0:root:/root:{shell}\n"
file = Path("/etc/passwd")
permission = file.stat().st_mode
writable = permission & 0o002
if (writable):
    with open("/etc/passwd", "a") as file:
        file.write("payload")
```


## Anna

how would handle this?




