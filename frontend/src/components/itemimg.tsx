import { useState } from "react"

function IMGItemBox({ imgurl, gifurl }: { imgurl: string, gifurl:string }) {

    const [isShown,setIsShown] = useState(false)

    return (
        <>
            <img
                onMouseEnter={()=>setIsShown(true)}
                onMouseLeave={()=>setIsShown(false)}
                className="itemimg"
                src={isShown ? gifurl : imgurl}
                alt="Item image"
            />
        </>
    )
}

export default IMGItemBox