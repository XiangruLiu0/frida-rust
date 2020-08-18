#pragma once

#include "frida-gum.h"

G_BEGIN_DECLS

#define GUM_TYPE_RUST_EVENT_SINK (gum_rust_event_sink_get_type ())
G_DECLARE_FINAL_TYPE (GumRustEventSink, gum_rust_event_sink, GUM,
    RUST_EVENT_SINK, GObject)

typedef struct {
  void* user_data;
  
  GumEventType (*query_mask)(void* user_data);
  void (*start)(void* user_data);
  void (*process)(void* user_data, const GumEvent* event);
  void (*flush)(void* user_data);
  void (*stop)(void* user_data);
} RustVTable;

struct _GumRustEventSink {
  GObject parent;
  RustVTable rust;
};

GumEventSink* gum_rust_event_sink_new(RustVTable rust);
void gum_rust_event_sink_reset(GumRustEventSink* self);

G_END_DECLS