import { useState } from 'react';
import { Greet } from "../../wailsjs/go/main/App";
import logo from '../assets/images/logo-universal.png';
import IMGItemBox from '../components/itemimg';
import gif from '../assets/fish-spinning.gif'

function Home() {

    const [resultText, setResultText] = useState("Please enter your name below 👇");
    const [name, setName] = useState('');
    const updateName = (e: any) => setName(e.target.value);
    const updateResultText = (result: string) => setResultText(result);

    function greet() {
        Greet(name).then(updateResultText);
    }


    return (
        <div>
            <IMGItemBox 
                imgurl={logo}
                gifurl={gif} />
        </div>
    )
}

export default Home