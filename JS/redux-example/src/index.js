import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';

//Este provider es nesesario para cargar un store para nuestra applicacion
import { Provider } from 'react-redux';

//importamos el store factory para nuestra applicacion
import createAppStore from './store/store.config';

//creamos un nuevo estore
const store = createAppStore();
ReactDOM.render(
	//pasamos como propiedad el store creado
	<Provider store={store}>
		<App />
	</Provider>,
	document.getElementById('root'));
