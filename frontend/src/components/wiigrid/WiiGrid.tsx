import "./WiiGrid.css";

function WiiGridLayout() {
    // To do:
    // Place a 3x4 grid
    // Able to take in any amount of items, if there are less than 3x4 then it is a placeholder img
    
    return (
        <>
            <article className="w-grid-container">
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>

                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
                <div className="w-grid-item"></div>
            </article>
        </>
    );
}

export default WiiGridLayout;