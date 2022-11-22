type Pointer<T> = {
    $: T;
}

type Nullable<T> = T | null;
type GLFWglproc = (() => void) | null;

export const GLFW_VERSION_MAJOR = 3;
export const GLFW_VERSION_MINOR = 3;
export const GLFW_VERSION_REVISION = 7;
export const GLFW_TRUE = 1;
export const GLFW_FALSE = 0;
export const GLFW_RELEASE = 0;
export const GLFW_PRESS = 1;
export const GLFW_REPEAT = 2;
export const GLFW_HAT_CENTERED = 0;
export const GLFW_HAT_UP = 1;
export const GLFW_HAT_RIGHT = 2;
export const GLFW_HAT_DOWN = 4;
export const GLFW_HAT_LEFT = 8;
export const GLFW_HAT_RIGHT_UP = 3;
export const GLFW_HAT_RIGHT_DOWN = 6;
export const GLFW_HAT_LEFT_UP = 9;
export const GLFW_HAT_LEFT_DOWN = 12;
export const GLFW_KEY_UNKNOWN = - 1;
export const GLFW_KEY_SPACE = 32;
export const GLFW_KEY_APOSTROPHE = 39;
export const GLFW_KEY_COMMA = 44;
export const GLFW_KEY_MINUS = 45;
export const GLFW_KEY_PERIOD = 46;
export const GLFW_KEY_SLASH = 47;
export const GLFW_KEY_0 = 48;
export const GLFW_KEY_1 = 49;
export const GLFW_KEY_2 = 50;
export const GLFW_KEY_3 = 51;
export const GLFW_KEY_4 = 52;
export const GLFW_KEY_5 = 53;
export const GLFW_KEY_6 = 54;
export const GLFW_KEY_7 = 55;
export const GLFW_KEY_8 = 56;
export const GLFW_KEY_9 = 57;
export const GLFW_KEY_SEMICOLON = 59;
export const GLFW_KEY_EQUAL = 61;
export const GLFW_KEY_A = 65;
export const GLFW_KEY_B = 66;
export const GLFW_KEY_C = 67;
export const GLFW_KEY_D = 68;
export const GLFW_KEY_E = 69;
export const GLFW_KEY_F = 70;
export const GLFW_KEY_G = 71;
export const GLFW_KEY_H = 72;
export const GLFW_KEY_I = 73;
export const GLFW_KEY_J = 74;
export const GLFW_KEY_K = 75;
export const GLFW_KEY_L = 76;
export const GLFW_KEY_M = 77;
export const GLFW_KEY_N = 78;
export const GLFW_KEY_O = 79;
export const GLFW_KEY_P = 80;
export const GLFW_KEY_Q = 81;
export const GLFW_KEY_R = 82;
export const GLFW_KEY_S = 83;
export const GLFW_KEY_T = 84;
export const GLFW_KEY_U = 85;
export const GLFW_KEY_V = 86;
export const GLFW_KEY_W = 87;
export const GLFW_KEY_X = 88;
export const GLFW_KEY_Y = 89;
export const GLFW_KEY_Z = 90;
export const GLFW_KEY_LEFT_BRACKET = 91;
export const GLFW_KEY_BACKSLASH = 92;
export const GLFW_KEY_RIGHT_BRACKET = 93;
export const GLFW_KEY_GRAVE_ACCENT = 96; 
export const GLFW_KEY_WORLD_1 = 161;
export const GLFW_KEY_WORLD_2 = 162;
export const GLFW_KEY_ESCAPE = 256;
export const GLFW_KEY_ENTER = 257;
export const GLFW_KEY_TAB = 258;
export const GLFW_KEY_BACKSPACE = 259;
export const GLFW_KEY_INSERT = 260;
export const GLFW_KEY_DELETE = 261;
export const GLFW_KEY_RIGHT = 262;
export const GLFW_KEY_LEFT = 263;
export const GLFW_KEY_DOWN = 264;
export const GLFW_KEY_UP = 265;
export const GLFW_KEY_PAGE_UP = 266;
export const GLFW_KEY_PAGE_DOWN = 267;
export const GLFW_KEY_HOME = 268;
export const GLFW_KEY_END = 269;
export const GLFW_KEY_CAPS_LOCK = 280;
export const GLFW_KEY_SCROLL_LOCK = 281;
export const GLFW_KEY_NUM_LOCK = 282;
export const GLFW_KEY_PRINT_SCREEN = 283;
export const GLFW_KEY_PAUSE = 284;
export const GLFW_KEY_F1 = 290;
export const GLFW_KEY_F2 = 291;
export const GLFW_KEY_F3 = 292;
export const GLFW_KEY_F4 = 293;
export const GLFW_KEY_F5 = 294;
export const GLFW_KEY_F6 = 295;
export const GLFW_KEY_F7 = 296;
export const GLFW_KEY_F8 = 297;
export const GLFW_KEY_F9 = 298;
export const GLFW_KEY_F10 = 299;
export const GLFW_KEY_F11 = 300;
export const GLFW_KEY_F12 = 301;
export const GLFW_KEY_F13 = 302;
export const GLFW_KEY_F14 = 303;
export const GLFW_KEY_F15 = 304;
export const GLFW_KEY_F16 = 305;
export const GLFW_KEY_F17 = 306;
export const GLFW_KEY_F18 = 307;
export const GLFW_KEY_F19 = 308;
export const GLFW_KEY_F20 = 309;
export const GLFW_KEY_F21 = 310;
export const GLFW_KEY_F22 = 311;
export const GLFW_KEY_F23 = 312;
export const GLFW_KEY_F24 = 313;
export const GLFW_KEY_F25 = 314;
export const GLFW_KEY_KP_0 = 320;
export const GLFW_KEY_KP_1 = 321;
export const GLFW_KEY_KP_2 = 322;
export const GLFW_KEY_KP_3 = 323;
export const GLFW_KEY_KP_4 = 324;
export const GLFW_KEY_KP_5 = 325;
export const GLFW_KEY_KP_6 = 326;
export const GLFW_KEY_KP_7 = 327;
export const GLFW_KEY_KP_8 = 328;
export const GLFW_KEY_KP_9 = 329;
export const GLFW_KEY_KP_DECIMAL = 330;
export const GLFW_KEY_KP_DIVIDE = 331;
export const GLFW_KEY_KP_MULTIPLY = 332;
export const GLFW_KEY_KP_SUBTRACT = 333;
export const GLFW_KEY_KP_ADD = 334;
export const GLFW_KEY_KP_ENTER = 335;
export const GLFW_KEY_KP_EQUAL = 336;
export const GLFW_KEY_LEFT_SHIFT = 340;
export const GLFW_KEY_LEFT_CONTROL = 341;
export const GLFW_KEY_LEFT_ALT = 342;
export const GLFW_KEY_LEFT_SUPER = 343;
export const GLFW_KEY_RIGHT_SHIFT = 344;
export const GLFW_KEY_RIGHT_CONTROL = 345;
export const GLFW_KEY_RIGHT_ALT = 346;
export const GLFW_KEY_RIGHT_SUPER = 347;
export const GLFW_KEY_MENU = 348;
export const GLFW_KEY_LAST = 348;
export const GLFW_MOD_SHIFT = 0x0001;
export const GLFW_MOD_CONTROL = 0x0002;
export const GLFW_MOD_ALT = 0x0004;
export const GLFW_MOD_SUPER = 0x0008;
export const GLFW_MOD_CAPS_LOCK = 0x0010;
export const GLFW_MOD_NUM_LOCK = 0x0020;
export const GLFW_MOUSE_BUTTON_1 = 0;
export const GLFW_MOUSE_BUTTON_2 = 1;
export const GLFW_MOUSE_BUTTON_3 = 2;
export const GLFW_MOUSE_BUTTON_4 = 3;
export const GLFW_MOUSE_BUTTON_5 = 4;
export const GLFW_MOUSE_BUTTON_6 = 5;
export const GLFW_MOUSE_BUTTON_7 = 6;
export const GLFW_MOUSE_BUTTON_8 = 7;
export const GLFW_MOUSE_BUTTON_LAST = 7;
export const GLFW_MOUSE_BUTTON_LEFT = 0;
export const GLFW_MOUSE_BUTTON_RIGHT = 1;
export const GLFW_MOUSE_BUTTON_MIDDLE = 2;
export const GLFW_JOYSTICK_1 = 0;
export const GLFW_JOYSTICK_2 = 1;
export const GLFW_JOYSTICK_3 = 2;
export const GLFW_JOYSTICK_4 = 3;
export const GLFW_JOYSTICK_5 = 4;
export const GLFW_JOYSTICK_6 = 5;
export const GLFW_JOYSTICK_7 = 6;
export const GLFW_JOYSTICK_8 = 7;
export const GLFW_JOYSTICK_9 = 8;
export const GLFW_JOYSTICK_10 = 9;
export const GLFW_JOYSTICK_11 = 10;
export const GLFW_JOYSTICK_12 = 11;
export const GLFW_JOYSTICK_13 = 12;
export const GLFW_JOYSTICK_14 = 13;
export const GLFW_JOYSTICK_15 = 14;
export const GLFW_JOYSTICK_16 = 15;
export const GLFW_JOYSTICK_LAST = 15;
export const GLFW_GAMEPAD_BUTTON_A = 0;
export const GLFW_GAMEPAD_BUTTON_B = 1;
export const GLFW_GAMEPAD_BUTTON_X = 2;
export const GLFW_GAMEPAD_BUTTON_Y = 3;
export const GLFW_GAMEPAD_BUTTON_LEFT_BUMPER = 4;
export const GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER = 5;
export const GLFW_GAMEPAD_BUTTON_BACK = 6;
export const GLFW_GAMEPAD_BUTTON_START = 7;
export const GLFW_GAMEPAD_BUTTON_GUIDE = 8;
export const GLFW_GAMEPAD_BUTTON_LEFT_THUMB = 9;
export const GLFW_GAMEPAD_BUTTON_RIGHT_THUMB = 10;
export const GLFW_GAMEPAD_BUTTON_DPAD_UP = 11;
export const GLFW_GAMEPAD_BUTTON_DPAD_RIGHT = 12;
export const GLFW_GAMEPAD_BUTTON_DPAD_DOWN = 13;
export const GLFW_GAMEPAD_BUTTON_DPAD_LEFT = 14;
export const GLFW_GAMEPAD_BUTTON_LAST = 14;
export const GLFW_GAMEPAD_BUTTON_CROSS = 0;
export const GLFW_GAMEPAD_BUTTON_CIRCLE = 1
export const GLFW_GAMEPAD_BUTTON_SQUARE = 2;
export const GLFW_GAMEPAD_BUTTON_TRIANGLE = 3;
export const GLFW_GAMEPAD_AXIS_LEFT_X = 0;
export const GLFW_GAMEPAD_AXIS_LEFT_Y = 1;
export const GLFW_GAMEPAD_AXIS_RIGHT_X = 2;
export const GLFW_GAMEPAD_AXIS_RIGHT_Y = 3;
export const GLFW_GAMEPAD_AXIS_LEFT_TRIGGER = 4;
export const GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER = 5;
export const GLFW_GAMEPAD_AXIS_LAST = 5;
export const GLFW_NO_ERROR = 0;
export const GLFW_NOT_INITIALIZED = 0x00010001;
export const GLFW_NO_CURRENT_CONTEXT = 0x00010002;
export const GLFW_INVALID_ENUM = 0x00010003;
export const GLFW_INVALID_VALUE = 0x00010004;
export const GLFW_OUT_OF_MEMORY = 0x00010005;
export const GLFW_API_UNAVAILABLE = 0x00010006;
export const GLFW_VERSION_UNAVAILABLE = 0x00010007;
export const GLFW_PLATFORM_ERROR = 0x00010008;
export const GLFW_FORMAT_UNAVAILABLE = 0x00010009;
export const GLFW_NO_WINDOW_CONTEXT = 0x0001000A;
export const GLFW_FOCUSED = 0x00020001;
export const GLFW_ICONIFIED = 0x00020002;
export const GLFW_RESIZABLE = 0x00020003;
export const GLFW_VISIBLE = 0x00020004;
export const GLFW_DECORATED = 0x00020005;
export const GLFW_AUTO_ICONIFY = 0x00020006;
export const GLFW_FLOATING = 0x00020007;
export const GLFW_MAXIMIZED = 0x00020008;
export const GLFW_CENTER_CURSOR = 0x00020009;
export const GLFW_TRANSPARENT_FRAMEBUFFER = 0x0002000A;
export const GLFW_HOVERED = 0x0002000B;
export const GLFW_FOCUS_ON_SHOW = 0x0002000C;
export const GLFW_RED_BITS = 0x00021001;
export const GLFW_GREEN_BITS = 0x00021002;
export const GLFW_BLUE_BITS = 0x00021003;
export const GLFW_ALPHA_BITS = 0x00021004;
export const GLFW_DEPTH_BITS = 0x00021005;
export const GLFW_STENCIL_BITS = 0x00021006;
export const GLFW_ACCUM_RED_BITS = 0x00021007;
export const GLFW_ACCUM_GREEN_BITS = 0x00021008;
export const GLFW_ACCUM_BLUE_BITS = 0x00021009;
export const GLFW_ACCUM_ALPHA_BITS = 0x0002100A;
export const GLFW_AUX_BUFFERS = 0x0002100B;
export const GLFW_STEREO = 0x0002100C;
export const GLFW_SAMPLES = 0x0002100D;
export const GLFW_SRGB_CAPABLE = 0x0002100E;
export const GLFW_REFRESH_RATE = 0x0002100F;
export const GLFW_DOUBLEBUFFER = 0x00021010;
export const GLFW_CLIENT_API = 0x00022001;
export const GLFW_CONTEXT_VERSION_MAJOR = 0x00022002;
export const GLFW_CONTEXT_VERSION_MINOR = 0x00022003;
export const GLFW_CONTEXT_REVISION = 0x00022004;
export const GLFW_CONTEXT_ROBUSTNESS = 0x00022005;
export const GLFW_OPENGL_FORWARD_COMPAT = 0x00022006;
export const GLFW_OPENGL_DEBUG_CONTEXT = 0x00022007;
export const GLFW_OPENGL_PROFILE = 0x00022008;
export const GLFW_CONTEXT_RELEASE_BEHAVIOR = 0x00022009;
export const GLFW_CONTEXT_NO_ERROR = 0x0002200A;
export const GLFW_CONTEXT_CREATION_API = 0x0002200B;
export const GLFW_SCALE_TO_MONITOR = 0x0002200C;
export const GLFW_COCOA_RETINA_FRAMEBUFFER = 0x00023001;
export const GLFW_COCOA_FRAME_NAME = 0x00023002;
export const GLFW_COCOA_GRAPHICS_SWITCHING = 0x00023003;
export const GLFW_X11_CLASS_NAME = 0x00024001;
export const GLFW_X11_INSTANCE_NAME = 0x00024002;
export const GLFW_NO_API = 0;
export const GLFW_OPENGL_API = 0x00030001;
export const GLFW_OPENGL_ES_API = 0x00030002;
export const GLFW_NO_ROBUSTNESS = 0;
export const GLFW_NO_RESET_NOTIFICATION = 0x00031001;
export const GLFW_LOSE_CONTEXT_ON_RESET = 0x00031002;
export const GLFW_OPENGL_ANY_PROFILE = 0;
export const GLFW_OPENGL_CORE_PROFILE = 0x00032001;
export const GLFW_OPENGL_COMPAT_PROFILE = 0x00032002;
export const GLFW_CURSOR = 0x00033001;
export const GLFW_STICKY_KEYS = 0x00033002;
export const GLFW_STICKY_MOUSE_BUTTONS = 0x00033003;
export const GLFW_LOCK_KEY_MODS = 0x00033004;
export const GLFW_RAW_MOUSE_MOTION = 0x00033005;
export const GLFW_CURSOR_NORMAL = 0x00034001;
export const GLFW_CURSOR_HIDDEN = 0x00034002;
export const GLFW_CURSOR_DISABLED = 0x00034003;
export const GLFW_ANY_RELEASE_BEHAVIOR = 0;
export const GLFW_RELEASE_BEHAVIOR_FLUSH = 0x00035001;
export const GLFW_RELEASE_BEHAVIOR_NONE = 0x00035002;
export const GLFW_NATIVE_CONTEXT_API = 0x00036001;
export const GLFW_EGL_CONTEXT_API = 0x00036002;
export const GLFW_OSMESA_CONTEXT_API = 0x00036003;
export const GLFW_ARROW_CURSOR = 0x00036001;
export const GLFW_IBEAM_CURSOR = 0x00036002;
export const GLFW_CROSSHAIR_CURSOR = 0x00036003;
export const GLFW_HAND_CURSOR = 0x00036004;
export const GLFW_HRESIZE_CURSOR = 0x00036005;
export const GLFW_VRESIZE_CURSOR = 0x00036006;
export const GLFW_CONNECTED = 0x00040001;
export const GLFW_DISCONNECTED = 0x00040002;
export const GLFW_JOYSTICK_HAT_BUTTONS = 0x00050001;
export const GLFW_COCOA_CHDIR_RESOURCES = 0x00051001;
export const GLFW_COCOA_MENUBAR = 0x00051002;
export const GLFW_DONT_CARE = -1;

// Context
export function glfwMakeContextCurrent(window: GLFWwindow): void;
export function glfwGetCurrentContext(): GLFWwindow;
export function glfwSwapInterval(interval: number): void;
export function glfwExtensionSupported(extension: string): boolean;
export function glfwGetProcAddress(procname: string): GLFWglproc;

// Initialization, version and error
export type GLFWerrorfun = (err: number, desc: string) => void;

export function glfwInit(): number;
export function glfwTerminate(): void;
export function glfwInitHint(hint: number, value: number): void;
export function glfwGetVersion(major: Pointer<number>, minor: Pointer<number>, rev: Pointer<number>): void;
export function glfwGetVersionString(): string;
export function glfwGetError(description?: Pointer<string>): number;
export function glfwSetErrorCallback(callback: GLFWerrorfun): GLFWerrorfun;

// Input handling
export type GLFWcursor = {}
export type GLFWmousebuttonfun = (window: GLFWwindow, button: number, action: number, mods: number) => void;
export type GLFWcursorposfun = (window: GLFWwindow, xpos: number, ypos: number) => void;
export type GLFWcursorenterfun = (window: GLFWwindow, entered: number) => void;
export type GLFWscrollfun = (window: GLFWwindow, xoffset: number, yoffset: number) => void;
export type GLFWkeyfun = (window: GLFWwindow, key: number, scancode: number, action: number, mods: number) => void;
export type GLFWcharfun = (window: GLFWwindow, codepoint: number) => void;
export type GLFWcharmodsfun = (window: GLFWwindow, codepoint: number, mods: number) => void;
export type GLFWdropfun = (window: GLFWwindow, count: number, paths: Pointer<string>) => void;
export type GLFWjoystickfun = (jid: number, event: number) => void;
export type GLFWgamepadstate = {
    buttons: number[],
    axes: number[]
}

export function glfwGetInputMode(window: GLFWwindow, mode: number): number;
export function glfwSetInputMode(window: GLFWwindow, mode: number, value: number): void;
export function glfwRawMouseMotionSupported(): boolean;
export function glfwGetKeyName(key: number, scancode: number): string;
export function glfwGetKeyScancode(key: number): number;
export function glfwGetKey(window: GLFWwindow, key: number): number;
export function glfwGetMouseButton(window: GLFWwindow, button: number): number;
export function glfwGetCursorPos(window: GLFWwindow, xpos: Pointer<number>, ypos: Pointer<number>): void;
export function glfwSetCursorPos(window: GLFWwindow, xpos: number, ypos: number): void;
export function glfwCreateCursor(image: GLFWimage, xhot: number, yhot: number): GLFWcursor;
export function glfwCreateStandardCursor(shape: number): GLFWcursor;
export function glfwDestroyCursor(cursor: GLFWcursor): void;
export function glfwSetCursor(window: GLFWwindow, cursor: GLFWcursor): void;
export function glfwSetKeyCallback(window: GLFWwindow, callback: GLFWkeyfun): void;
export function glfwSetCharCallback(window: GLFWwindow, callback: GLFWcharfun): void;
export function glfwSetCharModsCallback(window: GLFWwindow, callback: GLFWcharmodsfun): void;
export function glfwSetMouseButtonCallback(window: GLFWwindow, callback: GLFWmousebuttonfun): void;
export function glfwSetCursorPosCallback(window: GLFWwindow, callback: GLFWcursorposfun): void;
export function glfwSetCursorEnterCallback(window: GLFWwindow, callback: GLFWcursorenterfun): void;
export function glfwSetScrollCallback(window: GLFWwindow, callback: GLFWscrollfun): void;
export function glfwSetDropCallback(window: GLFWwindow, callback: GLFWdropfun): void;
export function glfwJoystickPresent(jid: number): boolean;
export function glfwGetJoystickAxes(jid: number, count: Pointer<number>): Float32Array;
export function glfwGetJoystickButtons(jid: number, count: Pointer<number>): Uint8Array;
export function glfwGetJoystickHats(jid: number, count: Pointer<number>): Uint8Array;
export function glfwGetJoystickName(jid: number): string;
export function glfwGetJoystickGUID(jid: number): string;
export function glfwSetJoystickUserPointer(jid: number, pointer: Pointer<void>): void;
export function glfwGetJoystickUserPointer(jid: number): Pointer<void>;
export function glfwJoystickIsGamepad(jid: number): boolean;
export function glfwSetJoystickCallback(callback: GLFWjoystickfun): void
export function glfwUpdateGamepadMappings(string: string): number;
export function glfwGetGamepadName(jid: number): string;
export function glfwGetGamepadState(jid: number, state: GLFWgamepadstate): number;
export function glfwSetClipboardString(window: GLFWwindow, string: string): void;
export function glfwGetClipboardString(window: GLFWwindow): string;
export function glfwGetTime(): number;
export function glfwSetTime(time: number): void;
export function glfwGetTimerValue(): number;
export function glfwGetTimerFrequency(): number;

// Monitors
export type GLFWmonitor = {};
export type GLFWmonitorfun = (monitor: GLFWmonitor, event: number) => void;
export type GLFWvidmode = {
    width: number,
    height: number,
    redBits: number,
    greenBits: number,
    blueBits: number,
    refreshRate: number
};
export type GLFWgammaramp = {
    red: number[],
    green: number[],
    blue: number[],
    size: number
};

export function glfwGetMonitors(count: Pointer<number>): GLFWmonitor[];
export function glfwGetPrimaryMonitor(): GLFWmonitor;
export function glfwGetMonitorPos(monitor: GLFWmonitor, xpos: Pointer<number>, ypos: Pointer<number>): void;
export function glfwGetMonitorWorkarea(
    monitor: GLFWmonitor,
    xpos: Pointer<number>,
    ypos: Pointer<number>,
    width: Pointer<number>,
    height: Pointer<number>
): void;
export function glfwGetMonitorPhysicalSize(
    monitor: GLFWmonitor,
    widthMM: Pointer<number>,
    heightMM: Pointer<number>
): void;
export function glfwGetContentScale(monitor: GLFWmonitor, xscale: Pointer<number>, yscale: Pointer<number>): void;
export function glfwGetMonitorName(monitor: GLFWmonitor): string;
export function glfwSetMonitorUserPointer(monitor: GLFWmonitor, pointer: Pointer<void>): void;
export function glfwGetMonitorUserPointer(monitor: GLFWmonitor): Pointer<void>;
export function glfwSetMonitorCallback(callback: GLFWmonitorfun): GLFWmonitorfun;
export function glfwGetVideoModes(monitor: GLFWmonitor, count: Pointer<number>): GLFWvidmode[];
export function glfwGetVideoMode(monitor: GLFWmonitor): GLFWvidmode;
export function glfwSetGamma(monitor: GLFWmonitor, gamma: number): void;
export function glfwGetGammaRamp(monitor: GLFWmonitor): GLFWgammaramp;
export function glfwSetGammaRamp(monitor: GLFWmonitor, ramp: GLFWgammaramp): void;

// Window handling
export type GLFWwindow = {};
export type GLFWwindowposfun = (window: GLFWwindow, xpos: number, ypos: number) => void;
export type GLFWwindowsizefun = (window: GLFWwindow, width: number, height: number) => void;
export type GLFWwindowclosefun = (window: GLFWwindow) => void;
export type GLFWwindowrefreshfun = (window: GLFWwindow) => void;
export type GLFWwindowfocusfun = (window: GLFWwindow, focused: number) => void;
export type GLFWwindowiconifyfun = (window: GLFWwindow, iconified: number) => void;
export type GLFWwindowmaximizefun = (window: GLFWwindow, maximized: number) => void;
export type GLFWframebuffersizefun = (window: GLFWwindow, width: number, height: number) => void;
export type GLFWwindowcontentscalefun = (window: GLFWwindow, xscale: number, yscale: number) => void;
export type GLFWimage = {
    width: number,
    height: number,
    pixels: Buffer;
};

export function glfwDefaultWindowHints(): void;
export function glfwWindowHint(hint: number, value: number): void;
export function glfwWindowHintString(hint: number, value: string): void;
export function glfwCreateWindow(
    width: number,
    height: number,
    title: string,
    monitor: Nullable<GLFWmonitor>,
    share: Nullable<GLFWwindow>
): GLFWwindow;
export function glfwDestroyWindow(window: GLFWwindow): void;
export function glfwWindowShouldClose(window: GLFWwindow): boolean;
export function glfwSetWindowShouldClose(window: GLFWwindow, value: boolean): void;
export function glfwSetWindowTitle(window: GLFWwindow, title: string): void;
export function glfwSetWindowIcon(window: GLFWwindow, count: number, images: GLFWwindow[]): void;
export function glfwGetWindowPos(window: GLFWwindow, xpos: Pointer<number>, ypos: Pointer<number>): void;
export function glfwSetWindowPos(window: GLFWwindow, xpos: number, ypos: number): void;
export function glfwGetWindowSize(window: GLFWwindow, width: Pointer<number>, height: Pointer<number>): void;
export function glfwSetWindowSizeLimits(
    window: GLFWwindow,
    minwidth: number,
    minheight: number,
    maxwidth: number,
    maxheight: number
): void;
export function glfwSetWindowAspectRatio(window: GLFWwindow, numer: number, denom: number): void;
export function glfwSetWindowSize(window: GLFWwindow, width: number, height: number): void;
export function glfwGetFramebufferSize(window: GLFWwindow, width: Pointer<number>, height: Pointer<number>): void;
export function glfwGetWindowFrameSize(
    window: GLFWwindow,
    left: Pointer<number>,
    top: Pointer<number>,
    right: Pointer<number>,
    bottom: Pointer<number>
): void;
export function glfwGetWindowContentScale(
    window: GLFWwindow,
    xscale: Pointer<number>,
    yscale: Pointer<number>
): void;
export function glfwGetWindowOpacity(window: GLFWwindow, opacity: Pointer<number>): void;
export function glfwSetWindowOpacity(window: GLFWwindow, opacity: number): void;
export function glfwIconifyWindow(window: GLFWwindow): void;
export function glfwRestoreWindow(window: GLFWwindow): void;
export function glfwMaximizeWindow(window: GLFWwindow): void;
export function glfwShowWindow(window: GLFWwindow): void;
export function glfwHideWindow(window: GLFWwindow): void;
export function glfwFocusWindow(window: GLFWwindow): void;
export function glfwRequestWindowAttention(window: GLFWwindow): void;
export function glfwGetWindowMonitor(window: GLFWwindow): Nullable<GLFWmonitor>;
export function glfwSetWindowMonitor(
    window: GLFWwindow,
    monitor: Nullable<GLFWmonitor>,
    xpos: number,
    ypos: number,
    width: number,
    height: number,
    refreshRate: number
): void;
export function glfwGetWindowAttrib(window: GLFWwindow, attrib: number): number;
export function glfwSetWindowAttrib(window: GLFWwindow, attrib: number, value: number): number;
export function glfwSetWindowUserPointer(window: GLFWwindow, pointer: Pointer<void>): void;
export function glfwGetWindowUserPointer(window: GLFWwindow): Pointer<void>;
export function glfwSetWindowPosCallback(window: GLFWwindow, cbfun: GLFWwindowposfun): void;
export function glfwSetWindowSizeCallback(window: GLFWwindow, cbfun: GLFWwindowsizefun): void;
export function glfwSetWindowCloseCallback(window: GLFWwindow, cbfun: GLFWwindowclosefun): void;
export function glfwSetWindowRefreshCallback(window: GLFWwindow, cbfun: GLFWwindowrefreshfun): void;
export function glfwSetWindowFocusCallback(window: GLFWwindow, cbfun: GLFWwindowfocusfun): void;
export function glfwSetWindowIconifyCallback(window: GLFWwindow, cbfun: GLFWwindowiconifyfun): void;
export function glfwSetWindowMaximizeCallback(window: GLFWwindow, cbfun: GLFWwindowmaximizefun): void;
export function glfwSetFramebufferSizeCallback(window: GLFWwindow, cbfun: GLFWframebuffersizefun): void;
export function glfwSetWindowContentScaleCallback(window: GLFWwindow, cbfun: GLFWwindowcontentscalefun): void;
export function glfwPollEvents(): void;
export function glfwWaitEvents(): void;
export function glfwWaitEventsTimeout(timeout: number): void;
export function glfwPostEmptyEvent(): void;
export function glfwSwapBuffers(window: GLFWwindow): void;
