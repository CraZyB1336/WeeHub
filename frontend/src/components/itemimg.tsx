function IMGItemBox({ imgurl }: { imgurl: string }) {

    return (
        <>
            <img
                className="itemimg"
                src={imgurl}
                alt="Item image"
            />
        </>
    )
}

export default IMGItemBox