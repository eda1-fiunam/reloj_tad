/*Copyright (C) 
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 * 2023 - francisco dot rodriguez at unam dot ingenieria dot edu
 */

#include <stdio.h>


//                   Reloj.h
typedef struct 
{
	int horas;
	int minutos;
} Reloj;



//                   Reloj.c

/**
 * @brief Imprime la hora de un reloj.
 *
 * @param this Referencia a un objeto Reloj.
 */
void Reloj_Imprime( const Reloj* this ) 
{
	printf( "%02d:%02d\n", this->horas, this->minutos );
}

/**
 * @brief Pone la hora a un reloj.
 *
 * @param this Referencia a un objeto Reloj.
 * @param horas Las horas (0-23)
 * @param minutos Los minutos (0-59)
 */
void Reloj_Poner( Reloj* this, int horas, int minutos )
{
	this->horas = horas;
	this->minutos = minutos;
}

/**
 * @brief Incrementa los minutos una unidad cada vez que es llamada.
 *
 * @param this Referencia a un objeto Reloj.
 */
void Reloj_Incrementar( Reloj* this )
{
	++this->minutos;
	if( this->minutos > 59 )
   {
		this->minutos = 0;

		++this->horas;
		if( this->horas > 23 )
      { 
         this->horas = 0; 
      }
	}
}


//                   main.c

int main()
{
	Reloj casio;
	Reloj swatch;

	Reloj_Poner( &casio, 12, 0 );
	printf( " Reloj 'casio' antes: " );
	Reloj_Imprime( &casio );

	Reloj_Poner( &swatch, 19, 30 );
	printf( "Reloj 'swatch' antes: " );
	Reloj_Imprime( &swatch );

   printf( "...\n" );
	for( size_t i = 0; i < 82; ++i )
   {
		Reloj_Incrementar( &casio );
		Reloj_Incrementar( &swatch );
	}

	printf( " Reloj 'casio' después: " );
	Reloj_Imprime( &casio );

	printf( "Reloj 'swatch' después: " );
	Reloj_Imprime( &swatch );
}

