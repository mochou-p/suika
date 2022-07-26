// suika

#version 430

uniform vec2 u_screen;

void main()
{
    vec2 uv = (gl_FragCoord.xy / u_screen) * 2.0 - 1.0;

    gl_FragColor = vec4(vec3(1.0) - vec3(abs(uv), uv.x + uv.y), 1.0);
}
