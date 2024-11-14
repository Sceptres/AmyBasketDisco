#ifndef COLOR_CLASS

#define COLOR_CLASS

/**
 * A class representing colors
 */
class Color {
    public:
        /**
         * Instantiate a color with the RGBA code of the color
         * 
         * @param[in] r The red component of the color
         * @param[in] g The green component of the color
         * @param[in] b The blue component of the color
         * @param[in] a The alpha component of the color
         */
        Color(float r, float g, float b, float a);

        /**
         * Instantiate a color with the RGB code of the color. Alpha set to 1.
         * 
         * @param[in] r The red component of the color
         * @param[in] g The green component of the color
         * @param[in] b The blue component of the color
         */
        Color(float r, float g, float b);
        const float r;
        const float g;
        const float b;
        const float a;
};

#endif