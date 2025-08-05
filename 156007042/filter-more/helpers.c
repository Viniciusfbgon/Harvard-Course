#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    int gx_array[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy_array[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_red = 0, gx_green = 0, gx_blue = 0, gy_red = 0, gy_green = 0, gy_blue = 0;
            int counter = 0;
            for (int updated_i = i - 1; updated_i < i + 2; updated_i++)
            {
                for (int updated_j = j - 1; updated_j < j + 2; updated_j++)
                {
                    if (!(updated_i < 0 || updated_j < 0 || updated_i >= height || updated_j >= width))
                    {
                        gx_red += gx_array[counter] * image[updated_i][updated_j].rgbtRed;
                        gx_green += gx_array[counter] * image[updated_i][updated_j].rgbtGreen;
                        gx_blue += gx_array[counter] * image[updated_i][updated_j].rgbtBlue;
                        gy_red += gy_array[counter] * image[updated_i][updated_j].rgbtRed;
                        gy_green += gy_array[counter] * image[updated_i][updated_j].rgbtGreen;
                        gy_blue += gy_array[counter] * image[updated_i][updated_j].rgbtBlue;
                    }
                    counter++;
                }
            }
            int final_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int final_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int final_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            image_copy[i][j].rgbtRed = (final_red > 255) ? 255 : final_red;
            image_copy[i][j].rgbtGreen = (final_green > 255) ? 255 : final_green;
            image_copy[i][j].rgbtBlue = (final_blue > 255) ? 255 : final_blue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_copy[i][j];
        }
    }
    return;
}
