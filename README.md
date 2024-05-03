# CUBOIDAL

NOTICE
---

This project was directly inspired by Hopson97's implementation of "MineCraft In One Week" that was released a long time ago. This project only uses some of the code from the original, most of everything else is unique and designed around some of the design philosophies of Suraj Sharma's project style.

A shout out is also made to YouTube personality "Suraj Sharma" for his SFML tutorial series, he made SFML much easier to understand and provided great examples of safe recursive header inclusion, plus some other helpful programming tidbits.

While this project uses some code and inspiration from Hopson97's project, a majority of this game's code is adapted by DreamHollow4219 to feel more "ordered" and have a better flow.

This project is unfinished and mostly exists as a base framework.

BRANCHES
---

`master` is the most stable branch of this project.

`devel` and numbered branches are experimental branches still in development.


HOW TO CONTRIBUTE
---

Committing changes to this repo should be done as follows:
Fork it. Seriously, I don't care.

Fork the project and submit a pull request from your repo. If the changes are compatible with the current version of the project, I'll bring them over.

Other appreciated but not required ways to support includes direct donations.

HOW IT WORKS
---

Detailed documentation for this program will be provided in due time.

Q & A FOR NON DEVS
---

**Will there be some kind of binary, game executable, whatever?**

DH (Project Lead):
That's the plan, yeah.

Even if this project's source code gets uploaded without .exe or a Linux ELF file,
there's a plan to add something like that ASAP so people can just play the game.

Jury is out for Apple based builds, sorry folks.
I might very seriously consider working on some kind of port for other platforms or devices,
especially since I know people love mobile versions of games.

But right now that's just not likely.

I'm planning on adding some API stuff so modding will be more fluid,
but that kind of implementation isn't happening anytime soon; especially without outside
help.

**"Why are there so many files in game projects? Is it necessary?"**
DH:
Unfortunately, yeah. You might need slightly fewer files in a well optimized 2D game,
but for 3D games you're usually going to see a lot of stuff.

Rendering stuff, graphical stuff, even more rendering stuff for better optimization,
it's a big mess. Ask any 3D programmer or artist working on a big 3D game.

**"Why is this programming stuff so confusing?"**

DH:
Please don't ask me.

I've been doing this for a couple of years and I'm still mystified about it all.

Q & A FOR DEVS
---

**"Why is the project lead so inactive on GitHub lately?"**

DH:
Unfortunately I have a lot going on and I won't be able to do much with any of my existing or future projects, I don't have the funding or motivation to do much but upload my proof-of-concepts and hope people find better ways to adapt them.

**"This code seems different from Hopson's project, why include the license?"**

DH:
Because the project itself is inspired by and uses snippets of code from his project in order to function.

The States, Linux scripts, configurations, and assets are all mine though.

Use Hopson's license if you make your own version of this, don't sour the legality or terms. Please.

**"Why do you use this style of coding or formatting for your project?"**

DH:
I really hope my style of formatting is easier to read for most developers.

I'm the kind of person that absolutely dreads trying to interpret other people's code
because so many programs out there are basically spaghetti or rarely commented.

I tried to do a fair blend of "clean code" and occasional commenting so most developers
would see what was going on underneath.

**"This debugger seems to mostly output strings rather than change or stop anything, is that intentional?"**

DH:
Absolutely.

Most of the time when I'm working on a project I benefit a lot more from having the program
report to me what it's doing at the time of execution.

It's like a psuedo trace system that leads me back to a relative location to figure out
where something went wrong.

I know I'll probably encounter bugs where this isn't as helpful but it works fine for now.

**"Why is there no dedicated renderer?"**

DH:
The main reason is that it's simply easier directly change visual effects in OpenGL by passing data directly from a function call to a value. That is to say that if I need to modify the uniforms directly, I can write up a function that immediately communicates to the object that something is changing.

While a dedicated renderer would make it easier to point to a single rendering location it can be extremely difficult to process visual effects in this manner without extreme modifications to the core of the project.

COMPILATION
---

To compile Cuboidal, you will need the SFML library.

Cuboidal functions on SFML library version 2.5.1 but is expected to work fine with versions like 2.6+

If any problems occur with SFML in later versions, please flag an issue and the development team will try to figure out what's not working.

*** Linux ***

Compiling the program on Linux is straightforward.

Make sure you have your distro's SFML package installed to your system, then run the `build.sh` command for a debug build. For a full installation to your system, you will need to run the `install.sh` command with sudo/wheel permissions.

If you are using a non-standard Linux distro or build the SFML source yourself, it should be possible to link that SFML source the old fashioned way by editing the CMakeLists.txt file to point at your compiled SFML source.

Please only install `master` branch versions of Cuboidal.
Installing in-progress builds of the program are highly discouraged; you should use `build.sh` and `run.sh` instead.

*** Windows ***

Nothing yet, stay tuned!

Compiling this project for Windows as-is is probably possible, provided a developer modifies a few things.

It just needs to follow the Windows style of directory access (like C:\Program Files and all that blah.)

KUDOS
---
Hopson97 for creating Minecraft-One-Week and inspiring others to create Minecraft-likes.

Suraj Sharma for his important lessons on states, inheritance, and program flow.

TheCherno for his game engine series and tutorials that helped with better understanding OpenGL.

The creators and maintainers of LearnOpenGL who made it possible to write most of the graphics for this project.
