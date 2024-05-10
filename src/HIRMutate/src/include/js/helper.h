#ifndef HM_JS_HELPER_H
#define HM_JS_HELPER_H

const char *gc = "function gc() {\n for (var i = 0; i < 100; i++) {\n    a = new Uint8Array(1024 * 1024);\n }\n}";

const char *do_nothing = "function doNothing() { }\n";

#endif