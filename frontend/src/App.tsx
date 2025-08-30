import { useEffect, useState } from 'react';
import logo from './assets/images/logo-universal.png';
import './App.css';
import { Greet } from "../wailsjs/go/main/App";
import Home from './pages/Home'
import TabBar from './components/TabBar';
import cursor from './assets/cursor.cur'

function App() {

    useEffect(() => {
        const interval = setInterval(() => {
            if (document.hasFocus()) {
                document.documentElement.style.cursor = `url(${cursor}), auto`;
                document.body.style.cursor = `url(${cursor}), auto`;
            } else {
                document.documentElement.style.cursor = 'default';
                document.body.style.cursor = 'default';
            }
        }, 500);

        return () => clearInterval(interval); // Cleanup on unmount
    }, []);


    return (
        <>
            <TabBar />
            <Home />
        </>
    )
}

export default App
