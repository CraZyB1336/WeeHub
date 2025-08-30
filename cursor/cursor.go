/* // go/cursor/cursor.go
package cursor

import (
  "context"
  "github.com/wailsapp/wails/v2/pkg/runtime"
)

// Cursor is our bound object
type Cursor struct{}

// CheckFocus returns true if the Wails window is currently active
func (c *Cursor) CheckFocus(ctx context.Context) bool {
  screens, _ := runtime.ScreenGetAll(ctx)
  for _, s := range screens {
    if s.IsCurrent {
      return true
    }
  }
  return false
}
 */