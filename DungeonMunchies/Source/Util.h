#ifndef UTIL_H
#define UTIL_H

///�H�U���U���
const char KEY_ESC = 27;
const char KEY_LEFT = 0x25; // keyboard���b�Y
const char KEY_UP = 0x26; // keyboard�W�b�Y
const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
const char KEY_DOWN = 0x28; // keyboard�U�b�Y
const char KEY_W = 0x57;
const char KEY_A = 0x41;
const char KEY_S = 0x53;
const char KEY_D = 0x44;
const char KEY_E = 0x69;
const char KEY_SPACE = 0x20;
const char KEY_SHIFT = 0x10;

// �w�q�U���d���s��
enum Stage {
	stage_boss,
	stage_props
};

#endif