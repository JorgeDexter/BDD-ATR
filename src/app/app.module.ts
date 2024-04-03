import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouteReuseStrategy } from '@angular/router';

import { IonicModule, IonicRouteStrategy } from '@ionic/angular';
import { environment } from '../environments/environment'; // Importa el entorno

import { AppComponent } from './app.component';
import { AppRoutingModule } from './app-routing.module';
import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import { getDatabase, provideDatabase } from '@angular/fire/database';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule, IonicModule.forRoot(), AppRoutingModule,
    provideFirebaseApp(() => initializeApp(environment.firebase)),
    provideDatabase(() => getDatabase()),
    provideFirebaseApp(() => initializeApp({"projectId":"bdd-atr","appId":"1:594964601880:web:5e2cc54d0470d7197db76d","databaseURL":"https://bdd-atr-default-rtdb.firebaseio.com","storageBucket":"bdd-atr.appspot.com","apiKey":"AIzaSyABAvj13tO6mdZZYd79EIy3mKqj0RrHNaI","authDomain":"bdd-atr.firebaseapp.com","messagingSenderId":"594964601880"}))],
  providers: [{ provide: RouteReuseStrategy, useClass: IonicRouteStrategy }],
  bootstrap: [AppComponent],
})
export class AppModule {}
