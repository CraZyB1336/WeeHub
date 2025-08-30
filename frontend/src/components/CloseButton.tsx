import './TabBar.css'
import {Quit} from '../../wailsjs/runtime'

function CloseButton() {

    const closeApp = () =>
    {
        Quit()
    };

    return (
        <button id='CloseButton' onClick={closeApp}>X</button>
    )
}

export default CloseButton