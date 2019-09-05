open ReactNative;

[@react.component]
let make = () => {
    // Example url didn't work so I used this one.
    let uri = "https://upload.wikimedia.org/wikipedia/commons/d/de/Bananavarieties.jpg"
    let source = Image.Source.fromUriSource(Image.uriSource(~uri, ~width=193., ~height=110., ()));
    <Image source/>
};
