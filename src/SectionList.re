open ReactNative;

[@bs.val] external alert : string => unit = "alert" ;

let styles = Style.(StyleSheet.create({
    "container": style(~flex=1., ~paddingTop=dp(22.), ()),
    "item": style(~padding=dp(10.), ~fontSize=18., ~height=dp(44.), ()),
    "sectionHeader": style(
        ~paddingTop=dp(2.),
        ~paddingLeft=dp(10.),
        ~paddingRight=dp(10.),
        ~paddingBottom=dp(2.),
        ~fontSize=14.,
        ~fontWeight=`bold,
        ~backgroundColor="rgba(247,247,247,1.0)",
        ()
    ),
}));

module SectionListBasics = {
    let makeSection = (~data,
                       ~key=?,
                       ~renderItem=?,
                       ~itemSeparatorComponent=?,
                       ~keyExtractor=?,
                       ()) => {
        "data": data,
        "key": key,
        "renderItem": renderItem,
        "ItemSeparatorComponent": itemSeparatorComponent,
        "keyExtractor": keyExtractor,
    };
    let sections = [|
        makeSection(~key="D", ~data = [|"Devin", "Dan", "Dominic"|], ()),
        makeSection(~key="J", ~data = [|"Jackson", "James", "Joel", "John", "Jillian", "Jimmy", "Julie"|], ()),
    |];

    let keyExtractor = (_item, index) => { Js.log(index) ; string_of_int(index) };

    let renderItem = (obj) => <Text style=styles##item>{React.string(obj##item)}</Text>;

    let renderSectionHeader = (obj : VirtualizedSectionList.renderSectionHeaderProps(string)) => {
        let key = switch obj##section##key {
            | Some(key) => key
            | None => "Default Section"
        };
        <Text style=styles##sectionHeader>
            {React.string(key)}
        </Text>
    };

    [@react.component]
    let make = () => {
        <View style=styles##container>
            <SectionList sections keyExtractor renderItem renderSectionHeader/>
        </View>
    }
}
