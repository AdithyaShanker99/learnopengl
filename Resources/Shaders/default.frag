#version 330 core
out vec4 FragColor;
in vec3 color;
in vec2 texCoords;
in vec3 Normal;
in vec3 crntPos;

uniform sampler2D tex0;
uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

void main()
{
   float ambient = 0.4;

   vec3 normal = normalize(Normal);
   vec3 lightDirection = normalize(lightPos - crntPos);

   float diffuse = max(dot(normal,lightDirection), 0.0f);
   float specularLight = 0.5f;
   vec3 viewDirection = normalize(cameraPos-crntPos);
   vec3 reflection = reflect(-lightDirection, normal);
   float specAmount = pow(max(dot(viewDirection,reflection),0.0f),5);
   float specular = specAmount*specularLight;
   FragColor = texture(tex0, vec2(texCoords.x, texCoords.y)) * lightColor * (diffuse+ambient+specular);
}