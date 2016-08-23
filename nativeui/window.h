// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WINDOW_H_
#define NATIVEUI_WINDOW_H_

#include "nativeui/container.h"
#include "ui/gfx/geometry/rect.h"

namespace nu {

// The native window.
NATIVEUI_EXPORT class Window : public base::RefCounted<Window> {
 public:
  struct Options {
    gfx::Rect content_bounds;
  };

  explicit Window(const Options& options);

  void SetContentView(Container* view);
  Container* GetContentView() const;

  void SetContentBounds(const gfx::Rect& bounds);
  gfx::Rect GetContentBounds() const;

  gfx::Rect ContentBoundsToWindowBounds(const gfx::Rect& bounds) const;
  gfx::Rect WindowBoundsToContentBounds(const gfx::Rect& bounds) const;

  void SetBounds(const gfx::Rect& bounds);
  gfx::Rect GetBounds() const;

  void SetVisible(bool visible);
  bool IsVisible() const;

 protected:
  virtual ~Window();

 private:
  friend class base::RefCounted<Window>;

  // Following platform implementations should only be called by wrappers.
  void PlatformInit(const Options& options);
  void PlatformSetContentView(Container* container);

  NativeWindow window_;
  scoped_refptr<Container> content_view_;
};

}  // namespace nu

#endif  // NATIVEUI_WINDOW_H_