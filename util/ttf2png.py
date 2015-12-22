import os
import sys
import string

# TODO: MACK - Vertical alignment of the lowercase letters :(
# TODO: MACK - Refactor this to use format strings, methods, etc.
# TODO: MACK - clean this up, test out lots of fonts

if (len(sys.argv) < 2):
    print('Usage: python ttf2png.py <TTF-FILE>')
    sys.exit(1)

fontpath = sys.argv[1]
fontname = fontpath[fontpath.rfind('/') + 1 : fontpath.rfind('.')]

# Options for the imagemagick "convert" command
options = {
    'background': 'none',
    'fill': 'gray75',
    'font': fontpath,
    'geometry': '{}x'.format(16 * len(open('chars.txt').read())),
    'gravity': 'center',
    'pointsize': '32', # This is somewhat arbitrary
}

command = (
    'convert '
    + ' '.join('-' + k + ' ' + v for (k, v) in options.items())
    + ' ' + 'label:@chars.txt'
    + ' ' + fontname + '.png'
)

os.system(command)
