import { useState } from 'react';
import { Greet } from "../../wailsjs/go/main/App";
import Grid from "../components/Grid";
import Item from "../components/item";

function Home() {

    const [resultText, setResultText] = useState("Please enter your name below 👇");
    const [name, setName] = useState('');
    const updateName = (e: any) => setName(e.target.value);
    const updateResultText = (result: string) => setResultText(result);

    function greet() {
        Greet(name).then(updateResultText);
    }

    // Create array of 8 placeholder items
    const placeholderItems = Array.from({ length: 20 }, (_, index) => ({
        id: index + 1,
        title: `Item ${index + 1}`,
        description: `Placeholder description for item ${index + 1}`
    }));

    return (
        <div style={{
            padding: '10%',
            minHeight: '100vh',
            boxSizing: 'border-box'
        }}>
            <Grid
                gap="40px"
                style={{
                    maxWidth: '100%',
                    width: '100%'
                }}
            >
                {placeholderItems.map((item) => (
                    <Item key={item.id} />
                ))}
            </Grid>
        </div>
    )
}

export default Home