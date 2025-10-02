#pragma once

// Provide fallbacks for protobuf attributes when compiling against
// older protobuf headers. Newer protobuf releases ship port_def.inc/port_undef.inc
// which define these macros themselves, so skip our shims when those headers are
// available to avoid redefinition errors.

#if !defined(PROTOBUF_COMPAT_HAS_OFFICIAL_PORT_MACROS)
#if defined(__has_include)
#if __has_include(<google/protobuf/port_def.inc>)
#define PROTOBUF_COMPAT_HAS_OFFICIAL_PORT_MACROS 1
#endif
#endif
#endif

#ifndef PROTOBUF_COMPAT_HAS_OFFICIAL_PORT_MACROS
#ifndef PROTOBUF_MUST_USE_RESULT
#define PROTOBUF_MUST_USE_RESULT
#endif

#ifndef PROTOBUF_ALWAYS_INLINE
#define PROTOBUF_ALWAYS_INLINE inline
#endif

#ifndef PROTOBUF_PREDICT_FALSE
#define PROTOBUF_PREDICT_FALSE(x) (x)
#endif

#ifndef PROTOBUF_PREDICT_TRUE
#define PROTOBUF_PREDICT_TRUE(x) (x)
#endif
#endif
