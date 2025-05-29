#version 330
vec3 aPos;
vec4 vColor;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}