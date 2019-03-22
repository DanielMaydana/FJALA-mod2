import React from 'react'
import './index.css'

function Button({title, id}){
    return (

        <button>
        {title} {id}
        </button>
    );
}

export default Button;