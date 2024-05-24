#include <stdio.h>
#include <stdint.h>

///holaaaa

int main() {
    FILE *f = fopen ("swt_data.dat", "rb"); //rb abre el archivo
    uint32_t header;
    fread (&header, sizeof (uint32_t), 1, f); //lee el archivo en el primer elemento de f (el archivo)
    uint32_t index = (header<<2) >> 2; //header & 0x3FFFFFFF; //ESTAMOS HACIENDO UNA AND // (H x 2)/ 2
    uint32_t type = header >> 30; // CADA DOS ES UN BYTE 30 00 00 00 00  // lo corre 30 lugares y se queda con los dos bits mas sign.
    //showBin (header); // 0001 0000 - 1010 0010 - 0101 0100 - 1100 0010;
    //0
    float data;
    fread (&data, sizeof (float), 1, f);
    printf ("index = %d\n", index);
    if (type == 0){
        printf ("Torque: %f Nm\n", data);}
    else
        {if (type == 1 )
           {printf ("Velocidad de giro: %f rad/s\n", data);} 
        else    
           {if (type == 2)
               {printf ("Potencia electrica: %f watts\n", data);} 
            else 
               {printf ("Invalido");
               }
           }
        }
    
    fclose (f);
    return 0; 
}