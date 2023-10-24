#line 1 "/home/blues/Documents/Code/Neopixel-Length-Finder/README.md"
# Neopixel-Length-Finder
There should be a way to figure out the length of a neopixel strip by pluging both ends into an arduino. Someone else probably already made something that does this, I didn't look very hard.

At the moment I've got the basic idea down sorta, though it is in dire need of comments.

Forseen issues:
 I doubt it functions at all as it has been ages since I've written arduino code and I currently have access to neither an arduino or neopixel strip. I think the idea shows promise, but I'm guessing the digitalread is going to happen after the strip sends down the data so it'll probably miss the data that gets through to it, I'll probably have to move it to an interrupt pin.

I might continue fiddling with this later if i have time