
#version 3.7;
global_settings {  assumed_gamma 1.0 }
//---------------------------------------

// PoVRay 3.7 Scene File " ... .pov"
// author:  ...
// date:    ...
//--------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
//--------------------------------------------------------------------------
// camera ------------------------------------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 125      // front view
                            location  <5.0 , 1.0 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 90   // diagonal view
                            location  <2.0 , 2.5 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90 // right side view
                            location  <3.0 , 1.0 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0.0 , 3.0 ,-0.001>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
camera{Camera_0}
// sun ---------------------------------------------------------------------
light_source{<1500,2500,-2500> color White}
// sky ---------------------------------------------------------------------
plane{<0,1,0>,1 hollow  
       texture{pigment{ bozo turbulence 0.85 scale 1.0 translate<5,0,0>
                        color_map { [0.5 rgb <0.20, 0.20, 1.0>]
                                    [0.6 rgb <1,1,1>]
                                    [1.0 rgb <0.5,0.5,0.5>]}
                       }
               finish {ambient 1 diffuse 0} }      
       scale 10000}
//------------------------------
fog{distance 300000 color White}
// sea ---------------------------------------------------------------------
plane{<0,1,0>, 0 
       texture{Polished_Chrome
               normal { crackle 0.15 scale <0.35,0.25,0.25> turbulence 0.5 } 
               finish { reflection 0.60 }}}

//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------

//----------------------------------- end
#declare Nr = clock ;

#local Wing = 
       cone { <0,0,0>,0.75,<0,1.00,0>,0.35  
              scale <1,1,0.1> 
              matrix<  1  , 0, 0,  // shearing in x
                     -0.25, 1, 0,
                       0  , 0, 1,
                       0  , 0, 0>            
            } // end of cone -------------------------------------

#declare torp = union{

 sphere { <0,0,0>, 0.5
          scale<5,1,1>  
          translate<-4,0,0>  
        }  // end of sphere -------------------------------------- 
 
       
 union{ 
         object{ Wing rotate <0*90,0,0>}
         object{ Wing rotate <1*90,0,0>}
         object{ Wing rotate <2*90,0,0>}
         object{ Wing rotate <3*90,0,0>}
           
          translate<-5.55,0,0>
      }
      
//translate<0,1*Nr,0>
//rotate<0,0,90>


texture { Chrome_Metal //pigment { color White *0.45}
           finish  { phong 1 reflection 0.05}
         } // end of texture

}// end of union

object{torp translate<clock,0,0> rotate<0,0,90>} 