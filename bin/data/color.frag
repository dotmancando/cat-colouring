// SIMPLE PIXELATION: looks more game-y
uniform sampler2DRect tex01;
varying vec3 pos;
uniform float pixelSize;
uniform float extraRed;
uniform float extraGreen;
uniform float extraBlue;
uniform float opacity;
uniform float newName;
uniform float dist;

bool outlineOn = false; // TURN TO 0 to TURN OUTLINE OFF
int lineThickness = 1; // HOW THICK IS THE OUTLINE (in pixels)

void main()
{
    float dx = pixelSize;
    float dy = pixelSize;
    vec2 Coord = vec2(dx * floor(pos.x / dx),
                      dy * floor(pos.y / dy));
    

    vec4 resultPixels = texture2DRect(tex01, Coord);
    float minV, maxV, delta, saturation;
    float totalColor = resultPixels[0] + resultPixels[1] + resultPixels[2];
    minV = min( resultPixels[0], resultPixels[1] );
    minV = min( minV, resultPixels[2] );
    
    maxV = max( resultPixels[0], resultPixels[1] );
    maxV = max( maxV, resultPixels[2] );
    
    float thisOpa;
    float thres = 540.0 - dist;
    
    if(newName < 0.5){ // opacity depends on how far it is from the bottom
//        thisOpa = pos.y / 540.0;
        thisOpa = opacity;
    }else{
        if(pos.y  > thres){
            thisOpa = (pos.y - thres)/ dist * opacity;
        }else{
            thisOpa = 0.0;
        }
    }
    
    
    delta = maxV - minV;
    if( maxV != 0.0 ){
        saturation = delta / maxV;
    }
    
    if(resultPixels[3] > 0.9){
        resultPixels[3] = 1.0;
    }else{
        resultPixels[3] = 0.0;
        resultPixels[0] = 0.0;
        resultPixels[1] = 0.0;
        resultPixels[2] = 0.0;
    }
    
    if(saturation < 0.8 && totalColor > 0.1 ){
        resultPixels[0] = extraRed;
        resultPixels[1] = extraGreen;
        resultPixels[2] = extraBlue;
        resultPixels[3] = thisOpa;
    }else{
        resultPixels[0] = 0.0;
        resultPixels[1] = 0.0;
        resultPixels[2] = 0.0;
        resultPixels[3] = 0.0;
    }
    gl_FragColor.rgba = resultPixels;
    

}



// ADVANCED PIXELATION: subsamples the square.
//uniform sampler2DRect tex01;
//varying vec3 pos;
//uniform float pixelSize;
//
//void main()
//{
//    float Pixels = 100.0;
//    float boxWidth = pixelSize;
//    float boxHeight = pixelSize;
//    vec2 Coord = vec2(boxWidth * floor(pos.x / boxWidth), boxHeight * floor(pos.y / boxHeight));
//    vec4 colors = vec4(0,0,0,0);
//    float total = boxWidth * boxHeight;
//
//    for (int x=0; x<int(boxWidth); x++){
//        for (int y=0; y<int(boxHeight); y++){
//            vec2 d = vec2(x,y);
//
//            if (texture2DRect(tex01, Coord+d).a == 1.0){
//                colors[0] += texture2DRect(tex01, Coord+d).r;
//                colors[1] += texture2DRect(tex01, Coord+d).g;
//                colors[2] += texture2DRect(tex01, Coord+d).b;
//                colors[3] += texture2DRect(tex01, Coord+d).a;
//            }
//        }
//    }
//    colors[0] = colors[0]/total;
//    colors[1] = colors[1]/total;
//    colors[2] = colors[2]/total;
//    colors[3] = colors[3];
//    gl_FragColor.rgba = colors;//texture2DRect(tex01, Coord);
//}