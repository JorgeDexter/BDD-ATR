import { Component, OnInit } from '@angular/core';
import { Database, ref, set } from '@angular/fire/database';

@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage implements OnInit {

  constructor(private database: Database) {}

  ngOnInit() {
    // Espera a que el DOM esté completamente cargado
    document.addEventListener('DOMContentLoaded', () => {
      const ventanas = document.querySelectorAll('.ventana');
      ventanas.forEach(ventana => {
        ventana.addEventListener('click', () => this.cambiarEstado(ventana.id));
      });
    });
  }

  cambiarEstado(area: string) {
    // Cambiar color de la ventana
    const ventana = document.getElementById(area);
    if (ventana) {
      ventana.style.backgroundColor = '#00FF00'; // Cambia a verde

      // Actualizar valor en la base de datos
      const route = ref(this.database, 'casa/' + area);
      set(route, true); // Establece el valor en true en la base de datos
    }
  }

}

