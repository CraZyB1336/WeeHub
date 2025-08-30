import { useState } from "react";
import "./WiiGrid.css";
import IMGItemBox from "../itemimg";
import logo from "../../assets/images/logo-universal.png"
import gif from "../../assets/fish-spinning.gif"

function WiiGridLayout() {
    // To do:
    // Have a useState for a custom type for both paths of itembox (logo and gif)
    
    
    return (
        <div className="w-grid-container">
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
            <IMGItemBox imgurl={logo} gifurl={gif}/>
        </div>
    );
}

export default WiiGridLayout;