# v0.1.1

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




