#include "helpers.h"
#include<math.h>
#include<cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    /* the for loop below Iterates through the image pixels and obtains the RGB values. Get the average of the RGB values and change
      the image pixels to that value, I have named it grascale_pixel_value.
      The everage will be high if the RGB values are high and low if the values are low*/

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            RGBTRIPLE image_pixel = image[i][j];
            int grayscale_pixel_value = round((image_pixel.rgbtRed + image_pixel.rgbtGreen + image_pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = grayscale_pixel_value;
        }
    }
}
//the max pixel value caps the maximum RGB value recomputed under sepia formulars does not exceed 255
int max_pixel_value(int new_pixel_value)
{
     return new_pixel_value > 255 ? 255 : new_pixel_value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE image_pixel = image[i][j];
            int originalRed = image_pixel.rgbtRed;
            int originalBlue = image_pixel.rgbtBlue;
            int originalGreen = image_pixel.rgbtGreen;

            image[i][j].rgbtRed = max_pixel_value(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtBlue =  max_pixel_value(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
            image[i][j].rgbtGreen = max_pixel_value(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
        }
    }
}
//swap function is used to swap pixels in the reflect function
void swap_pixels(RGBTRIPLE * pixel_a, RGBTRIPLE * pixel_b)
{
    RGBTRIPLE temp = *pixel_a;
    *pixel_a = *pixel_b;
    *pixel_b = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    /*to reflect an image, we iterate over the pixels and swap the pixel at the image[i][j] position  with the one image[i][width -1-j]
    where i iterates over the image's height and j iterates over half the width of the image */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap_pixels(&image[i][j], &image[i][width - 1 - j]);
        }
    }

}
bool isValidPixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE computeBlurredPixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int red_pixel, blue_pixel, green_pixel;

    red_pixel = blue_pixel = green_pixel = 0;

    int valid_pixels_count = 0;

    /* loop through the pixel and move one step back and forward from each pixel in a 'box blur' concept.
    for each color value, give it a new value by averaging the color values of neighboring pixels.*/

    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (isValidPixel(new_i, new_j, height, width))
            {
                valid_pixels_count++;
                red_pixel += image[new_i][new_j].rgbtRed;
                green_pixel += image[new_i][new_j].rgbtGreen;
                blue_pixel += image[new_i][new_j].rgbtBlue;
            }
        }
    }

    RGBTRIPLE blurredImagePixel;

    blurredImagePixel.rgbtRed = round((float)red_pixel / valid_pixels_count);
    blurredImagePixel.rgbtGreen = round((float)green_pixel / valid_pixels_count);
    blurredImagePixel.rgbtBlue = round((float)blue_pixel / valid_pixels_count);

    return blurredImagePixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurredImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blurredImage[i][j] = computeBlurredPixel(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurredImage[i][j];
        }
    }
}
