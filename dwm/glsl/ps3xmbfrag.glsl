#version 330 core
in vec3 vEC;
out vec4 FragColor;

void main()
{
    const vec3 up = vec3(0.0, 0.0, 1.0);
    vec3 x = dFdx(vEC);
    vec3 y = dFdy(vEC);
    vec3 normal = normalize(cross(x, y));
    float c = 1.0 - dot(normal, up);
    c = (1.0 - cos(c * c)) / 3.0;
    FragColor = vec4(0.8, 0.9, 1.0, c * 2.0);
}
