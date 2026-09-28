# This patch would dedicated only and for only debunking the idea of "static analysis look for credential file"

## Foreword

when searching for a way to prevent the privilege escalation whom exploiting the weak permission on /etc/passwd this idea came across. Do a whole static system scan for the specific keyword. Yes, its grep essentially.

witty comment such as labelling me over-engineer happen often.

This fuckers don't understand it. How necessary it is in context of learning.

pass a buffer into a pattern looking function.

What's the point of it?. Where is the fun?

well.... what all this knowledge serve anyway. I won't get a job with knowing any of this.

My idealistic self
My pathetic idealistic self.

Does this really necessary?

### A few days after Foreword

I think i will make v0.1.3 to be a vulnerability check. I could use shell script to do this but i've talk about the flaw in scripting for portability. Not all machine use bash as its script, but every machine this AV made for is complying POSIX, therefore its a must for me to avoid the usage of shell scripting language.

### AnnaKav must and mustn't


## TODO 

1. Grep a keyword (If it's possible, i want to optimize the grep)
2. Small check for vulnerability (for now, it's maybe only /etc/passwd permission check)




