#define PI 3.141592653589793240  
  
float Perlin(int n) {  
  n = (n << 13) ^ n;  
  return 1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0;      
}  
  
float CosineInterpolate (float a, float b, float x) {  
  float f = (1.0 - cos (x * PI)) * 0.5;  
  return  a * (1.0 - f) + b * f;  
}  
  
float SmoothedNoise(int v) {  
  return Perlin(v) / 2  +  Perlin(v-1) / 4  +  Perlin(v+1) / 4;  
}  
  
int FastFloor (float v) { return (int) (v < 0) ? v - 1 : v; }  
  
float InterpolatedNoise (float v) {  
  int i = FastFloor(v);  
  float v1 = SmoothedNoise (i);  
  float v2 = SmoothedNoise (i + 1);  
  return CosineInterpolate(v1, v2, v - i);  
}  
  
float PerlinNoise(float v)  
{  
    float total = 0;  
    float amplitude = 1.0f;  
    float frequency = 1.0f;  
    for( int i = 0 ; i < 2; i++)  
    {  
        total += InterpolatedNoise (v * frequency) * amplitude;  
        frequency *= 2.0f;  
        amplitude *= 0.666f;  
    }  
    return total;  
}  