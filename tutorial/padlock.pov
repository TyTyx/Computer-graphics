#include "colors.inc" 
#include "textures.inc"

camera{
        location<0,0,-6>
        look_at<0,0,0>
}

light_source{<15,25,-25> color White}

background { color Grey }

#declare shackle = union
{
    intersection
    {
        torus { 0.75, 0.25
                rotate<90,0,0>
              }
        box{<-1,1,-0.25>,<1,0,0.25>}
    }

    cylinder{ <0.75, 0, 0>, <0.75,-0.25, 0>, 0.25}
    cylinder{ <-0.75, 0, 0>, <-0.75,-1.5, 0>, 0.25}

    texture { Rust }

}      

#declare body = union
{
    box{<-1,-2.25,-0.5>,<1,-0.25,0.5>}
    texture{ Rusty_Iron }
    
}

#declare key = union
{
    cylinder{<0,0,0.1>,<0,0,-0.1>, 0.5}
    box{<-0.2,0,-0.1>,<0.2,2,0.1>}
    texture{ New_Brass }
    translate<0,-3,0>
}

#declare lock = union
{
    object { shackle
    #if (clock >0) translate <0, clock/135, 0> #end}
    
    object{ body }
    
    object { key
    #if (clock < 0)
        rotate <0,90-clock,0>
    #else
        rotate <0,90,0>
    #end }
    
    translate<0,1,0>
}

object { lock }