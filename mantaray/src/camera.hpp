#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "hittable.hpp"
#include "rtweekend.hpp"

class camera
{
    public:
    double aspect_ratio = 1.0;
    int image_width = 100;
    int samples_per_pixel = 10; // count of random samples for each pixel

    void render(const hittable& world)
    {
        initialize();

        // Render 

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++)
        {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << '\n' << std::flush;
            for (int i = 0; i < image_width; i++)
            {
                colour pixel_colour(0,0,0);
                for (int sample = 0; sample < samples_per_pixel; sample++)
                {
                    ray rayo = get_ray(i,j);
                    pixel_colour += ray_colour(rayo, world);
                }
                write_colour(std::cout, pixel_samples_scale * pixel_colour);
            }
        }
        std::clog << "\rDone.                   \n";

    }

    private:
    int image_height;
    point3 camera_center;
    point3 firstPixel_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
    double pixel_samples_scale; // colour scale factor for a summ of pixel samples
    
    void initialize()
    {
        // calculate the image height and ensure its at least 1
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;
        camera_center = point3(0, 0, 0);

        pixel_samples_scale = 1.0 / samples_per_pixel;

        // viewport dimensions
        double focal_length = 1.0;
        double viewport_height = 2.0;
        double viewport_width = viewport_height * (double(image_width) / image_height);
    
        // calculate the vectors across the horizontal and down the vertical viewport edges 
        vec3 viewport_u = vec3(viewport_width, 0, 0);
        vec3 viewport_v = vec3(0, -viewport_height, 0);

        // calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // calculate the location of the upper left pixel
        auto viewport_upper_left = camera_center
                                    - vec3(0, 0, focal_length)
                                    - viewport_u/2
                                    - viewport_v/2;

        firstPixel_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    ray get_ray(int i, int j) const
    {
        // Construct a camera ray originating from the origin and directed at randomly sampled
        // point around the pixel location i, j.

        auto offset = sample_square();
        auto pixel_sample = firstPixel_loc + ((i + offset.x()) * pixel_delta_u) + ((j + offset.y()) * pixel_delta_v);

        auto ray_origin = camera_center;
        auto ray_direction = pixel_sample - ray_origin;
        return ray(ray_origin, ray_direction);
    }

    vec3 sample_square() const 
    {
        // Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit square.
        return vec3(random_double() - 0.5, random_double() - 0.5, 0);
    }

    colour ray_colour(const ray& rayo, const hittable& world)
    {
        hit_record rec;
        if (world.hit(rayo, interval(0, inf), rec))
        {
            return 0.5 * (rec.normal + colour(1, 1, 1));
        } 
    
        vec3 unit_direction = unit_vector(rayo.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * colour(1.0, 1.0, 1.0) + a * colour(0.5, 0.7, 1.0);    
    }
};

#endif