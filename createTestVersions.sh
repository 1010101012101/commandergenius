#!/bin/sh

# put date on the filename
dt=`date +%b%d%y-%H%M`

# Windows Version
cp ./Win32/CommanderGenius.exe ./CGenius.exe
zip CG-SVN-W32-$dt.zip ./CGenius.exe
zip CG-SVN-W32-$dt.zip ./resolutions.cfg
zip CG-SVN-W32-$dt.zip ./changelog.txt
zip CG-SVN-W32-$dt.zip ./readme.txt
rm ./CGenius.exe

# Linux 64-bit Version
cp ./Linux64/CommanderGenius ./CGenius
zip CG-SVN-Linux64-$dt.zip ./CGenius
zip CG-SVN-Linux64-$dt.zip ./data/resolutions.cfg
zip CG-SVN-Linux64-$dt.zip ./changelog.txt
zip CG-SVN-Linux64-$dt.zip ./readme.txt
rm ./CGenius

# Linux 32-bit Version
#zip CG-SVN-Linux32-$dt.zip ./build/Linux32/CGenius
#zip CG-SVN-Linux32-$dt.zip ./data/resolutions.cfg
#zip CG-SVN-Linux32-$dt.zip ./changelog.txt
#zip CG-SVN-Linux32-$dt.zip ./readme.txt

# upload the packages
#rsync -e ssh CG-SVN-W32-$dt.zip gerstrong,clonekeenplus@frs.sourceforge.net:/home/frs/project/c/cl/clonekeenplus/
#rsync -e ssh CG-SVN-Linux32-$dt.zip gerstrong,clonekeenplus@frs.sourceforge.net:/home/frs/project/c/cl/clonekeenplus/
#rsync -e ssh CG-SVN-Linux64-$dt.zip gerstrong,clonekeenplus@frs.sourceforge.net:/home/frs/project/c/cl/clonekeenplus/