/*
 * gex.h
 *
 * game graphics
 *
 * MIT License (see: LICENSE)
 * Copyright (c) 2023 Tomaz Stih
 *
 * 22.01.2023   tstih
 *
 */
#include <platform/gex.h>
#include <stdio.h>

void * gex_query_image(uint8_t location) {
    for(uint8_t i=0;i<NUMIMAGES;i++) {
        if (images[i].location==location) {
            /* load image and return ptr to it */
            uint16_t len=IMG_SIZE-1;
            return fload(images[i].name, NULL, images[i].offset, &len);
        }
    }
    return NULL; /* not found! */
}

void gex_release_image(void *img) {
    if (img!=NULL) free(img);
}