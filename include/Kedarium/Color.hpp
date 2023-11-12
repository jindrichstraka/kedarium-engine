#ifndef KDR_COLOR_HPP
#define KDR_COLOR_HPP

#include <stdint.h>

namespace kdr
{
  namespace Color
  {
    /**
     * Structure representing color in RGB format.
     */
    struct RGB
    {
      float red;
      float green;
      float blue;

      /**
       * Constructor initializing RGB values.
       *
       * @param red   Red channel value (0-255).
       * @param green Green channel value (0-255).
       * @param blue  Blue channel value (0-255).
       */
      RGB(
        const uint8_t red,
        const uint8_t green,
        const uint8_t blue
      ) : red(red / 255.f), green(green / 255.f), blue(blue / 255.f)
      {}
    };

    /**
     * Structure representing color in RGBA format.
     */
    struct RGBA
    {
      float red;
      float green;
      float blue;
      float alpha;

      /**
       * Constructor initializing RGBA values.
       *
       * @param red   Red channel value (0-255).
       * @param green Green channel value (0-255).
       * @param blue  Blue channel value (0-255).
       * @param alpha Alpha (transparency) channel value (0.0 to 1.0).
       */
      RGBA(
        const uint8_t red,
        const uint8_t green,
        const uint8_t blue,
        const float alpha
      ) : red(red / 255.f), green(green / 255.f), blue(blue / 255.f), alpha(alpha)
      {}
    };

    /**
     * Constant representing the RGBA color black (fully opaque).
     */
    inline const kdr::Color::RGBA Black {0, 0, 0, 1.f};
    /**
     * Constant representing the RGBA color white (fully opaque).
     */
    inline const kdr::Color::RGBA White {255, 255, 255, 1.f};
    /**
     * Constant representing the RGBA color red (fully opaque).
     */
    inline const kdr::Color::RGBA Red {255, 0, 0, 1.f};
    /**
     * Constant representing the RGBA color green (fully opaque).
     */
    inline const kdr::Color::RGBA Green {0, 255, 0, 1.f};
    /**
     * Constant representing the RGBA color blue (fully opaque).
     */
    inline const kdr::Color::RGBA Blue {0, 0, 255, 1.f};
  }
}

#endif // KDR_COLOR_HPP
